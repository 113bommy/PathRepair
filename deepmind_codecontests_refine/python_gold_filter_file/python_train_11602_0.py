n = int(input())
pat = []; 
for _ in range(n):
    x = input()
    pat.append(x)
ans = ["#"]*(len(pat[0]))
idx = set()
res = ""
for word in pat:
	for j in range(len(pat[0])):
		if word[j] != "?" and ans[j] == "#" and (j not in idx):
			ans[j] = word[j]
		elif word[j] != "?" and ans[j] != "#" and ans[j] != word[j]:
			ans[j] = "?"
			idx.add(j)
for x in range(len(pat[0])):
	res += ans[x]
ele = set(res)
# if len(pat[0]) == 1 and not (len(set(pat)) == 1):
# 	print("?")
# else:
print(res.replace("#", "x"))
