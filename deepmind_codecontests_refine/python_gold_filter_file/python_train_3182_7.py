n=int(input())
patterns=list(map(int,input().split()))
texts=[]
for i in range(n):
	texts.append(input().split())

test=True

for i in range(n):
	pattern=patterns[i]
	text=texts[i]
	voyels=0
	for ch in text:
		voyels+=ch.count("a")+ch.count("e")+ch.count("i")+ch.count("o")+ch.count("u")+ch.count("y")
	if voyels!=pattern:
		test=False
		break

if test:
	print("YES")
else:
	print("NO")