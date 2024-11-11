sym = list(map(str, input().split()))
n = int(input())

if n%2 == 0:
    print("undefined")
else:
    dict = {'<':0, '^': 1, '>': 2, 'v': 3}
    print("cw") if dict[sym[len(sym)-1]] == (dict[sym[0]] + n)%4 else print("ccw")
