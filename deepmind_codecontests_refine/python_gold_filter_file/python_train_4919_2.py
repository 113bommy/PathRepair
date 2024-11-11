n,s = map(int, input().split())
if(s<2*n):
    print("NO")
else:
    #print("YES\n"+'2 '*(n-1)+str(s-(2*(n-1)))+"\n1")
    print("YES\n"+'1 '*(n-1)+str(s-n+1),n)