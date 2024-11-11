a,b,c=[int(input()) for i in ' '*3]
print(max(a*b*c,a*(b+c),(a+b)*c,a+b+c))