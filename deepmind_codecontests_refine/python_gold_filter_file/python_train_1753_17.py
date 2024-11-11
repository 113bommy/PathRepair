def main():
    K, A, B = map(int, input().split())
    if K <= A: return 1
    if B >= A: return -1
    d = A-B
    K -= A
    if(K % d == 0): return 2 * (K//d) + 1
    return (K // d + 1) * 2 + 1

if __name__ == '__main__':
    print(main())