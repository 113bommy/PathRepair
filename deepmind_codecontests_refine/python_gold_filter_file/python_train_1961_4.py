n = input()
ans1=sum(int(i)for i in n)
ans2=int(n[0])-1+9*(len(n)-1)
print(max(ans1,ans2))