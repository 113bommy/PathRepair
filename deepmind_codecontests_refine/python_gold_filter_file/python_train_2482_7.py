S_p=input()
T=input()

k=[]
for i in range(len(S_p)-len(T)+1):
	S_sub = S_p[i:i+len(T)]
	if all(s in (t, "?") for s, t in zip(S_sub, T)):
		k.append(i)


if k:
	S=S_p[:k[-1]]+T+S_p[k[-1]+len(T):]
	print(S.replace("?", "a"))
else:
	print("UNRESTORABLE")