import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
yet = [a[i]!=b[i] for i in range(n)]

prev2 = b[0]
prev = b[1]
i = 2
count = n - sum(yet)
ans = 0
while count<n:
    current = b[i]
    if prev2==prev and (yet[i-1] or yet[i-2]):
        ans = -1
        break
    if  prev==current and (yet[i-1] or yet[i]):
        ans = -1
        break
        
    if yet[i-1] and prev2<prev>current:
        if a[i-1]>max(prev2, current):
            num = (prev-a[i-1])//(prev2+current)
            prev -= num*(prev2+current)
            b[i-1] = prev
            ans += num
            if prev!=a[i-1]:
                ans = -1
                break
            yet[i-1] = False
            count += 1
        else:
            if prev<=current+prev2:
                ans = -1
                break
            num = (prev-max(prev2, current))//(prev2+current) + int((prev-max(prev2, current))%(prev2+current)>0)
            prev -= num*(prev2+current)
            b[i-1] = prev
            if prev==a[i-1]:
                yet[i-1] = False
                count += 1
            elif prev<=0:
                ans = -1
                break
            ans += num
            
    prev2, prev = prev, current
    i += 1
    i %= n
print(ans)
