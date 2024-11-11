import sys
input = sys.stdin.readline
for _ in range(int(input())):
    s=input().rstrip()
    ans = zeroes = 0
    n = len(s)
    for i in range(n):
        if s[i] == '0':
            zeroes+=1
        else:
            for j in range(1,min(19,n-i+1)):
                k=int(s[i:i+j],2)
                if zeroes + j>=k:ans+=1
                else:continue
            zeroes = 0
    print(ans)
