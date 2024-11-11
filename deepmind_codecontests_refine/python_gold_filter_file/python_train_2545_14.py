a,b,c,d=map(int,input().split())
if abs(c-a)>0 and abs(d-b)>0 and abs(c-a)==abs(d-b):
    print(c,b,a,d)
elif (abs(c-a)>0 and abs(d-b)==0) or (abs(c-a)==0 and abs(d-b)>0):
    if abs(c-a)>0:
        print(a,b+(c-a),c,d+(c-a))
    else:
        print(a+(d-b),b,c+(d-b),d)
else:
    print("-1")