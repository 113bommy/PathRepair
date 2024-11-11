a,b,c,d,e=map(int,input().split())
f=a*b+2*d
g=a*c+2*e
if f<g:print('First')
elif f>g:print('Second')
else:print('Friendship')