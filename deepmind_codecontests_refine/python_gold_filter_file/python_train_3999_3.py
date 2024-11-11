n=int(input())
count=0
check=0
for i in range(n):
	s=input()
	if check!=s:
		count+=1

	check=s
print(count)

