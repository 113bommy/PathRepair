n = int(input())
# l = []

lt = lte = 2*10**9
gt = gte = -2*(10**9)

for _ in range(n):
	t1, t2, t3 = input().split()
	t2 = int(t2)

	if t3 == "Y":
		if t1==">=":
			gte = max(gte, t2)
		elif t1==">":
			gt = max(gt, t2)
		elif t1=="<=":
			lte = min(lte, t2)	
		else:
			lt = min(lt, t2)
	else:
		if t1==">=":
			lt = min(lt, t2)
		elif t1==">":
			lte = min(lte, t2)
		elif t1=="<=":
			gt = max(gt, t2)
		else:
			gte = max(gte, t2)

# print(lt, lte, gt, gte)
m1 = min(lt-1, lte)
m2 = max(gt+1, gte)

# print(m1, m2)

if m1<m2:
	print("Impossible")
else:
	print((m1+m2)//2)

# if lte>gte:
# 	print("Impossible")
# else:
# 	print((lte+gte)//2)	

# lt = list(filter(lambda x:x[0]=="<", l))
# lte = list(filter(lambda x:x[0]=="<=", l))
# gt = list(filter(lambda x:x[0]==">", l))
# gte = list(filter(lambda x:x[0]==">=", l))

# c = d = -1000000001
# a = b = 1000000001

# if len(lt)!=0:
# 	a = min(lt, key=lambda x:x[1])[1]
# if len(lte)!=0:
# 	b = min(lte, key=lambda x:x[1])[1]
# if len(gt)!=0:
# 	c = max(gt, key=lambda x:x[1])[1]
# if len(gte)!=0:
# 	d = max(gte, key=lambda x:x[1])[1]

# print(a, b, c, d)
# m1 = max(c, d)
# m2 = min(a, b)
# print(m1, m2)
# if m1>m2:
# 	print("Impossible")
# else:
# 	print((m1+m2)//2)	

# ma = 999999999999



"""
for q in l:	
	if q[2]=="Y":
		if q[0]==">":
			mi_temp = int(q[1])+1
			if mi_temp<mi:
				mi = mi_temp
		elif q[0]==">=":
			mi_temp = int(q[1])
			if mi_temp<mi:
				mi = mi_temp
		elif q[0]=="<":
			ma_temp = int(q[1])-1
			if ma_temp>ma:
				ma = ma_temp
		elif q[0]=="<=":
			ma_temp = int(q[1])
			if ma_temp>ma:
				ma = ma_temp
	else:
		if q[0]==">":
			ma_temp = int(q[1])
			if ma_temp>ma:
				ma = ma_temp
		elif q[0]==">=":
			ma_temp = int(q[1])-1
			if ma_temp>ma:
				ma = ma_temp
		elif q[0]=="<":
			mi_temp = int(q[1])
			if mi_temp<mi:
				mi = mi_temp
		elif q[0]=="<=":
			mi_temp = int(q[1])+1
			if mi_temp<mi:
				mi = mi_temp
	
	print(mi_temp, ma_temp, mi, ma)
	if mi_temp>ma_temp:
		print("Impossible")
		break			

if mi<=ma:
	print(mi_temp)

"""