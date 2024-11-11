import math

def solve(n):
    if n == 2:
        return 1.0
    each_angle = math.pi / n
    height = 0
    width = 0
    for i in range(n):
        angle = each_angle * i
        height += math.sin(angle) * 1.0
        width += abs(math.cos(angle)) * 1.0
    if width > height:
        sectors = n // 2
        angle = each_angle * (0.5 + sectors / 2) - math.pi / 4
        ans = width * math.cos(angle)
    else:
        ans = height
    # print(height, width, ans)
    return ans

def main():
    T = int(input())
    for _ in range(1, T + 1):
        n = int(input())
        print(solve(n))

if __name__ == '__main__':
    main()