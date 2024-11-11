from math import ceil
def check(sym,n,m,r):
    count_sym=0
    count_oth=0
    for i in range(n,m,r):
        if st[i] == sym:
            count_sym += 1
        else:
            count_oth += 1
        if count_sym >= count_oth and i!=m-r:
            return 0
    return 1

for _ in range(1):
    n=int(input())
    st=list(input().strip())
    if n%2==1:
        print(":(")
        continue
    if check(")",0,n,1) + check("(",n-1,-1,-1) <2:
        print(":(")
        continue
    count_f=n//2 -st.count("(")
    count_b=n//2 -st.count(")")
    count=0
    i=0
    while count <count_f:
        if st[i] == "?":
            st[i] ="("
            count+=1
        i+=1
    while count <count_b+count_f:
        if st[i] =="?":
            st[i] =")"
            count+=1
        i+=1
    for i in st:
        print(i,end='')