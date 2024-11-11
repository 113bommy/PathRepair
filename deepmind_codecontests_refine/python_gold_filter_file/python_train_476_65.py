s,v1,v2,t1,t2 = [int(x) for x in input().split()]
total1 = (v1*s) + (2*t1)
total2 = (v2*s) + (2*t2)
if total1<total2:
	print("First")
elif total2<total1:
	print("Second")
else:
	print("Friendship")