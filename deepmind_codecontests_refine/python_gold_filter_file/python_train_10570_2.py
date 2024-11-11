a=int(input())
s=[int(i) for i in input().split()]
s.sort()
s.reverse()
ans=2*s[0]-sum(s)+1
print(ans)