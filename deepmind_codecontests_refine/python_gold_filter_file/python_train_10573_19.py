a,b,c,d=map(int,input().split())
print(256*(min(a,c,d))+32*(min(b,(a-min(a,c,d)))))