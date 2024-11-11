x=int(input())
for i in range(x):
    y=list(input())
    if(len(y)>1):
        if(y[0]=="?" and y[1]!="c"):
            y[0]="c"
        elif y[0]=="?":
            y[0]="a"
    q=True
    for j in range(1,len(y)-1):
        if y[j]=="?" and y[j-1]!="a" and (y[j+1]!="a" ):
            y[j]="a"
        if y[j]=="?" and y[j-1]!="b" and (y[j+1]!="b" ):
            y[j]="b"
        if y[j]=="?" and y[j-1]!="c" and (y[j+1]!="c" ):
            y[j]="c"
    if len(y)>1:
        if(y[len(y)-1]=="?" and y[len(y)-2]!="c"):
            y[len(y)-1]="c"
        elif y[len(y)-1]=="?":
            y[len(y)-1]="a"
    elif y[0]=="?":
        y[0]="a"
    for j in range (len(y)-1):
        if y[j]==y[j+1]:
            q=False
    if q:
        print("".join(y))
    else:
        print("-1")