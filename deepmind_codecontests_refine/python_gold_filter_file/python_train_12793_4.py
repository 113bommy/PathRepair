h1,h2=map(int,input().split())
k1,k2=map(int,input().split())
a,b,c,d=map(int,input().split())
v=a*h1+(h1//10)*c+b*h2+(h2//20)*d
w=a*k1+(k1//10)*c+b*k2+(k2//20)*d
print("even" if v==w else ( "hiroshi" if v > w else "kenjiro" ))