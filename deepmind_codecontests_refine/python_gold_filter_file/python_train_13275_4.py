n=int(input())%360
if n<=45: print(0)
elif n<=90+45: print(1)
elif n<=180+45: print(2)
elif n<270+45: print(3)
else: print(0)
