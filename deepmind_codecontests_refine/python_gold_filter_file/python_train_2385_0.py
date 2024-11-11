while 1:
    n=int(input())
    if n==0:break
    l=d=mi=cl=cm=cd=0
    for i in range(n):
        t,M=input().split()
        M=int(M)
        h,m=map(int,t.split(":"))
        if m>M:M+=60
        a=M-m<=8
        if 11<=h<15:cl+=1;l+=a
        elif 18<=h<21:cd+=1;d+=a
        elif 21<=h or h< 2:cm+=1;mi+=a
    print('lunch', l*100//cl if cl else 'no guest')
    print('dinner', d*100//cd if cd else 'no guest')
    print('midnight', mi*100//cm if cm else 'no guest')