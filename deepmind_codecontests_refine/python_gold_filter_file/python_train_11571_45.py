list_int_input = lambda inp: list(map(int, inp.split()))
int_input = lambda inp: int(inp)
string_to_list_input = lambda inp: list(inp)

n,v=map(int,input().split())
val=v-1+int(((n-v)*(n-v+1))/2)
if n>v:
    print(val)
else:
    print(n-1)