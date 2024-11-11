s = int(input())
rs = []
for i in range(s):
    a= int(input())
    b= list(map(int,input().split()))
#     rs.append(b)
# # print(rs)
# for i in rs:
    count,sm = 0,0
    for val in b:
        if val%2 !=0:
            count +=1
    #count the odd
        sm += val
    if sm%2 !=0:
        rs.append('YES')
    # elif count%2 ==0 and count>2:  
    #     rs.append('YES')
    elif count > 0 and count < a: 
        rs.append('YES')
    else: 
        rs.append('NO')
for i in rs:
    print(i)