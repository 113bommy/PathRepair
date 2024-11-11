from sys import stdin, stdout

prime = list()
factor = list()
count = list()
dist = list()
N = 0

def find_prime():
    global prime
    for i in range(2, 5010):
        is_prime = True
        for j in prime:
            if i % j == 0:
                is_prime = False
                break
        if is_prime is True:
            prime.append(i)

def calculate_factor(max):
    global prime
    global factor
    global dist
    factor = [[0 for x in range(len(prime))] for y in range(5010)] 
    dist = [0] * (max+1)
    d = 0
    for i in range(1, max+1):
        temp = i
        factor[i] = list(factor[i-1])
        for j,x in enumerate(prime):
            while temp % x == 0:
                factor[i][j] +=1
                temp = temp / x
                d += 1
            if temp == 1:
                dist[i] = d 
                break
            
def dynamic_count():
    global count
    for i in range (1,len(count)):
        count[i] += count[i-1]

def moving(i, left, right, d, current_factor):
    global count
    global prime
    global factor
    global N
    while (factor[left][i] == factor[right][i]):
        d += ((2 * (count[right] - count[left-1])) - N) * (factor[right][i] - current_factor[i])
        current_factor[i] = factor[right][i]
        i -= 1
        if i < 0:
            return d
    d += ((2 * (count[right] - count[left-1])) - N) * (factor[left][i] - current_factor[i])
    current_factor[i] = factor[left][i]
    
    
    temp_left = right
    while temp_left >= left:
        if (factor[temp_left-1][i] != factor[right][i] or temp_left == left ) and count[right] - count[temp_left-1] > int(N/2):
            if (temp_left > left):
                d += ((2 * (count[temp_left-1] - count[left-1]))) * (factor[left][i] - current_factor[i]) 
            return moving(i, temp_left, right, d, current_factor)
        elif factor[temp_left-1][i] != factor[right][i]:
            i -= 1
            right = temp_left - 1
            if i < 0:
                return d
        temp_left -= 1
    return d

def unanem():
    global prime
    global count
    global N
    
    if count[1] > int(N/2):
        return 0
    current_factor = [0] * 5010
    if count[5000] - count[4998] > int(N/2):
        return moving(len(prime)-3, 4999, 5000, 0, current_factor)
    for i,x in enumerate(prime):
        counter = 0
        if i == 0:
            counter = count[1]
        else:
            counter = count[prime[i] - 1] - count[prime[i-1] - 1]
        if counter>int(N/2):
            return moving (i, prime[i-1], prime[i] - 1, 0 , current_factor)
    return 0

def main():
    global prime
    global factor
    global count
    global N
    global debugs
    N = int(stdin.readline())
    num_list = list(map(int, stdin.readline().split()))
    max = 0
    for i in num_list:
        if max < i:
            max = i
    
    
    count = [0] * (5010)
    for i in num_list:
        count[i] += 1
            
    find_prime()
    calculate_factor(max)
    dynamic_count()
    
    d = unanem()
    overall_dist = 0
    for i,c in enumerate(count):
        if i == max + 1:
            break
        if i == 0:
            continue
        overall_dist += (count[i] - count[i-1])*dist[i]
    print(overall_dist - d)
    

main()
    