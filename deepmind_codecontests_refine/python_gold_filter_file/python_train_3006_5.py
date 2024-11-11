for _ in[0]*int(input()):
 a,b,c,d,e,f=map(float,input().split())
 x=((a*a+b*b)*(d-f)+(c*c+d*d)*(f-b)+(e*e+f*f)*(b-d))/2/(a*(d-f)+c*(f-b)+e*(b-d))
 y=((a*a+b*b)*(c-e)+(c*c+d*d)*(e-a)+(e*e+f*f)*(a-c))/2/(b*(c-e)+d*(e-a)+f*(a-c))
 print('%.3f %.3f %.3f'%(x,y,((x-a)**2+(y-b)**2)**.5))
