s = input()
K = int(input())

se = set()
for i in range(1,min(len(s)+1,K+1)):
	for j in range(len(s)-i+1):
		se.add(s[j:j+i])
print(sorted(list(se))[K-1])