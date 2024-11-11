from sys import stdin, stdout

def main():
    n = int(stdin.readline())
    arr = list(map(int, stdin.readline().split()))
    ans = 0
    for bit in range(29):
        mask = (1<<bit+1)-1
        bit0 = []
        bit1 = []
        for x in arr:
            if x&(1<<bit): bit1.append(x)
            else: bit0.append(x)
        arr = bit0 + bit1
        temp_arr = [mask&x for x in arr]
        above = (1<<(bit+1))
        current = (1<<bit)
        abc = above + current
        j1 = j2 = j3 = 0
        res = 0
        for i,x in enumerate(reversed(temp_arr)):
            while j1 < n and temp_arr[j1] + x < current:
                j1+=1
            while j2 < n and temp_arr[j2] + x < above:
                j2+=1
            while j3 < n and temp_arr[j3] + x < abc:
                j3+=1
            r1 = (n-i) - j3 -1
            if r1 < 0:
                r1 = 0
            r2 = min(n-i-1, j2) - j1
            if r2 < 0:
                r2 = 0
            res += (r1 + r2) % 2
        if res % 2 == 1:
            ans+= current
    stdout.write(str(ans))
    
main()
        