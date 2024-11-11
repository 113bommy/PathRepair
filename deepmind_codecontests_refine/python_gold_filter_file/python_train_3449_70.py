import math
t = int(input())
temp  =0
gem = 0
diff = 0
if t==1:
	print("1")
	print("1")

for i in range(2,10):
	if t%i==0 and i<t:
		cal = int(t/i)
		pro = i
		temp=1
		gem = cal
if temp == 0:
   cal = t
   pro = 1
   gem = t
if t!= 1:
   print(gem)
   for i in range(0,cal):
	   print(pro,end=" ")
