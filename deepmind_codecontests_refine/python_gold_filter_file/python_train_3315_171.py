a,b=map(int,input().split())
print(["Possible","Impossible"][a%3==b%3 and (a%3==1 or a%3==2)])