t=int(input())
for k in range(1,t+1) :
    n=int(input())
    upper=input()
    lower=input()
    i=0
    j=0
    while( (i==0 or i==1) and (j>=0 and j<n ) ) :
        if ( i==0 ) :
            if ( int(upper[j]) == 1 or int(upper[j]) == 2 ) :
                j=j+1
            elif (int(lower[j])==1 or int(lower[j])==2 ):
                i=3
            else :
                i=1
                j=j+1
        else :
            if ( int(lower[j]) ==1 or int(lower[j]) == 2 ) :
                j= j+1
            elif ( int(upper[j])==1 or int(upper[j])==2 ):
                i=3
            else :
                j=j+1
                i=0
    if (i==1 and j==n) :
        print("YES")
    else :
        print("NO")