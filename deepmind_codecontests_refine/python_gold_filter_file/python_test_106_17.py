problem_num = int(input())
for i in range(problem_num):
    num = int(input())
    lst = []
    for i in range(2,2+num):
        lst.append(str(i))
    lst = ' '.join(lst)
    print(lst)