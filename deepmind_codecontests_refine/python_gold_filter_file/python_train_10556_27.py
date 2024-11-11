s = str(input())
e = s.split(" ")
news = []
answer = ""
for i in range(len(e)):
    news.append(int(e[i]))
if news[0] > 0 and news[1] > 0:
    answer = "0 " + str(abs(news[0])+abs(news[1])) + " " + str(abs(news[0])+abs(news[1])) + " 0"
elif news[0] > 0 and news[1] < 0:
    answer = "0 " + str(-((abs(news[0])+abs(news[1])))) + " " + str((abs(news[0])+abs(news[1]))) + " 0"
elif news[0] < 0 and news[1] > 0:
    answer = str(-(abs(news[0])+abs(news[1]))) + " 0 0 " + str(abs(news[0])+abs(news[1]))
elif news[0] < 0 and news[1] < 0:
    answer = str(-(abs(news[0])+abs(news[1]))) + " 0 0 " + str(-(abs(news[0])+abs(news[1])))
print(answer)