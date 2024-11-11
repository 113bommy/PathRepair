import sys

def read_input():
    count = int(sys.stdin.readline())
    grades = [int(n) for n in sys.stdin.readline().split()]

    return (count, grades)


count, grades = read_input()

pro_rated = [grade / count for grade in sorted(grades)]
average = sum(pro_rated)

if average >= 4.5:
    print(0)
else:
    labs, contribution = 0, 5 / count
    while pro_rated and average < 4.49999999:
        pro_rated_grade = pro_rated.pop(0)
        delta = contribution - pro_rated_grade
        average += delta
        labs += 1

    print(labs)
