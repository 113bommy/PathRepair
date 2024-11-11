c = ['a1','a8','h1','h8']
a = ['a2','a3','a4','a5','a6','a7']
h = ['h2','h3','h4','h5','h6','h7']
f = ['b1','c1','d1','e1','f1','g1']
l = ['b8','c8','d8','e8','f8','g8']

s = input()
if s in c:
	print(3)
elif s in a or s in h or s in f or s in l:
	print(5)
else:
	print(8)