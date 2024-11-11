list_int_input = lambda inp: list(map(int, inp.split()))
int_input = lambda inp: int(inp)
string_to_list_input = lambda inp: list(inp)

n=int_input(input())

for i in range(9,0,-1):
    if n%i==0:
        print(int(n/i))
        a=[i for j in range(int(n/i))]
        print(' '.join(list(map(str,a))))
        break