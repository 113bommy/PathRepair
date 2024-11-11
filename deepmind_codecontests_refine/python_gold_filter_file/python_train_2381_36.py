while 1:
    try:a,b,c,d,e,f=map(int,input().split())
    except:break
    x=(c*d-a*f)/(b*d-a*e)
    print("%.3f %.3f"%((c-b*x)/a,x))