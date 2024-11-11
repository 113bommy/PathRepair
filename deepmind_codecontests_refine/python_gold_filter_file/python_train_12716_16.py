a,b,c = map(int,input().split())
def f():
    if a==b:
        return 2*a+2*c
    else:
        return 2*c+min(a,b)*2+1
print(f())