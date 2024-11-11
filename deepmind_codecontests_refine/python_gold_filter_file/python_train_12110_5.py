parse = lambda st: map(int, st.split())

def solve(n, m, grades):
    res = set()
    for i in range(m):
        highest = None
        best = 0
        for j in range(n):
            if grades[j][i] > best:
                best = grades[j][i]
                highest = []
                highest.append(j)
            elif grades[j][i] == best:
                highest.append(j)
        res.update(set(highest))
    return len(res)

def solve2(n, m, grades):
    res = set()
    subjects = [[grades[j][i] for j in range(n)] for i in range(m)]
    for grades in subjects:
        _max = max(grades)
        for student, grade in enumerate(grades):
            if grade == _max:
                res.add(student)
    return len(res)

if __name__ == '__main__':
    n, m = parse(input())
    grades = [[int(x) for x in input()] for _ in range(n)]
    res = set()
    subjects = [[grades[j][i] for j in range(n)] for i in range(m)]
    for grades in subjects:
        _max = max(grades)
        for student, grade in enumerate(grades):
            if grade == _max:
                res.add(student)
    print(len(res))
