if __name__ == "__main__":
    n = int(input())
    grades = list(map(int,input().split()))
    grades.sort()
    required = 4.5
    redo = 0
    i = 0
    while round(sum(grades)/n , 2) < required:
        redo = redo + 1
        grades[i] = 5
        i = i + 1    
    print(redo)