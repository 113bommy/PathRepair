problems_times = input().split()
problems_times = list(map(int, problems_times))

problems_wrong = input().split()
problems_wrong = list(map(int, problems_wrong))

problems_hack = input().split()
h1, h2  = int(problems_hack[0]), int(problems_hack[1])

total_score = 0
problems_scores = [500, 1000, 1500, 2000, 2500]
for i in range(0, len(problems_times)):
    Xi = problems_scores[i]
    Mi = problems_times[i]
    Wi = problems_wrong[i]
    score = max(0.3*Xi, (1-(Mi/250))*Xi-50*Wi)
    total_score += score
total_score += h1 * 100
total_score -= h2 * 50

print(int(total_score))
