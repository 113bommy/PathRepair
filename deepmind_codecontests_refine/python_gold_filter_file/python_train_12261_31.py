s=input()
ans=0
for i in range(1,4):
	if s.count("R"*i):
		ans=max(ans,i)
print(ans)
