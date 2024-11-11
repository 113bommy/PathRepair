test_case=int(input())
for i in range(test_case):
    values=list(map(int,input().split(' ')))
    print(max(values[0],values[1]),max(values[1],values[2]),max(values[1],values[2]))