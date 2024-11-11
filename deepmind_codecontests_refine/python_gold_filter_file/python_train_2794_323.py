x,a,b=map(int,input().split())
print('A' if min(abs(a-x),abs(b-x))==abs(a-x) else 'B')
