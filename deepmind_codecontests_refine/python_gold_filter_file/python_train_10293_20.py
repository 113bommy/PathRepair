n=int(input())
a_list=[int(i) for i in input().split()]

center=round(sum(a_list)/n)
ans=0
for a in a_list:
    ans+=(a-center)**2
print(ans)