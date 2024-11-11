n = int(input())
s = input()
l = list(map(int, input().split()))
# if n==1:
# 	print(-1)
answer = 9999999999
for i in range(len(l)-1):
	if s[i] == "R" and s[i+1]=="L":
		answer = min(answer, (l[i+1] - l[i])//2)
	
if answer == 9999999999:
	print(-1)
else:
	print(answer)