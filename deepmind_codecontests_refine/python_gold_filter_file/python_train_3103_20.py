n=int(input())
s=list(map(int,input().split()))
print(min([abs(sum(s[:i])-sum(s[i:])) for i in range(n)]))