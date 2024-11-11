N=input()
ans1=sum(int(i)for i in N)
ans2=int(N[0])-1+9*(len(N)-1)
print(max(ans1,ans2))