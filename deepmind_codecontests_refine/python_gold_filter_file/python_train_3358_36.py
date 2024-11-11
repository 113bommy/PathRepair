test_case=int(input())
for i in range(test_case):
    l=[]
    k=1
    length=int(input())
    for j in range(1,length+1):
        l.append(str(1))
        k+=j
    print(' '.join(l))