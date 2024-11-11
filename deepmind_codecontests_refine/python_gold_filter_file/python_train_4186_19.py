t=int(input())
for i in range(t):
    n=int(input())
    s = input()
    if(s.count('1')==0):
        print(n)
    else:
        x = s.index('1')
        y = s.rindex('1')
        print(max(2*(x+1),2*(n-x),2*(y+1),2*(n-y)))