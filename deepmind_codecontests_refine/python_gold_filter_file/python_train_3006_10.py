for _ in[0]*int(input()):
 a,b,c,d,e,f=map(float,input().split())
 s,t,u=a*a+b*b,c*c+d*d,e*e+f*f
 x=(s*(d-f)+t*(f-b)+u*(b-d))/2/(a*(d-f)+c*(f-b)+e*(b-d))
 y=(s*(c-e)+t*(e-a)+u*(a-c))/2/(b*(c-e)+d*(e-a)+f*(a-c))
 print(f'{x:.3f} {y:.3f} {((x-a)**2+(y-b)**2)**.5:.3f}')
