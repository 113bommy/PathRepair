def solution(n, b):
    if n <= 2 and b == [b[0]] * n:
        return -1
    return f'1 {b.index(min(b)) + 1}'
 
 
def main():
    packs = int(input())
    balloons = input().split()
    print(solution(packs, balloons))
 
 
if __name__ == '__main__':
    main()