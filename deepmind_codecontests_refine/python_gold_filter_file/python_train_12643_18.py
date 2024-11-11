# link: https://codeforces.com/problemset/problem/450/B

def solve(x,y,n):
    if x==0 and y==0:
        return (0)
    first_term = x
    second_term = y
    info = [x, y, (y-x), x * (-1)]
    dummy_x = y-x
    dummy_y = x * (-1)
    while dummy_x != first_term or dummy_y != second_term:
        last_x = dummy_x
        last_y = dummy_y
        info.append(last_y-last_x)
        info.append(last_x * (-1))
        dummy_x = info[-2]
        dummy_y = info[-1]
    info.pop()
    info.pop()      
    count = len(info)
    if n%count == 0:
        return (info[-1] % (10**9 + 7))
    else:
        index = (n%count) - 1
        return (info[index] % (10**9 + 7))            

if __name__ == "__main__":
    i = input
    x,y = map(int, i().split())
    n = int(i())
    result = solve(x,y,n)
    print(result)