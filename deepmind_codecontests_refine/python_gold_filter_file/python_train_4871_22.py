H,W=map(int,input().split())
print(((W+1)//2)*((H+1)//2)+(H//2)*(W//2) if H!=1 and W!=1 else 1)