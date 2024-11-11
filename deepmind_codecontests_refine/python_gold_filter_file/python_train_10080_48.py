s = input()
K = int(input())

sub = set()

for i in range(len(s)):
	for j in range(i + 1,i + K + 1):
		sub.add(s[i:j])

ans = list(sorted(sub))

print(ans[K - 1])