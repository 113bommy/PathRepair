def solve(x):
  if x<0:
    A=round((5*x*x*x+((-x)**0.5))*100)
    print("f({}) =".format(x),"%.2f"%((A/100)+0.002))
    return 0
  else:
    A=round((5*x*x*x+(x**0.5))*100)
    if A>=40000:
      A='MAGNA NIMIS!'
      print('f('+str(x)+')','=',A)
    else:
      print("f({}) =".format(x),"%.2f"%((A/100)+0.002))
    return 0

Q=[int(input()) for i in range(11)]
for i in range(10,-1,-1):
  solve(Q[i])