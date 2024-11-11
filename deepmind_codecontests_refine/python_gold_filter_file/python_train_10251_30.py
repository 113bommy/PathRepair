def solution(n):
    if n %2 ==0:
        return n//2
    else:
        return (n-1)//2 -n
if __name__ == "__main__":
    print(solution(int(input())))