q = int(input())
for i in range(q):
    n = int(input())
    s_numbers = input().split()
    numbers=[]
    sum = 0
    for j in range(n):
        numbers.append(int(s_numbers[j]))
        numbers.sort()
    for k in range(n-1,-1,-1):
        if (numbers[k] > 2048):
            sum += 0
        elif (numbers[k] == 2048):
            print("YES")
            break
        elif (numbers[k] < 2048):
            if (sum < 2048):
                sum += numbers[k]
        if (sum == 2048):
            print("YES")
            break
        if (k==0):
            print("NO")
        

        