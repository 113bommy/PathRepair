N = int(input())
List = []
count = 0
for _ in range(N) :
    List.append(int(input()))
cmp = 0
for i in range(0, N) :
    if List[i] == cmp :
        pass
    else :
        cmp = List[i]
        count += 1
print(count)
