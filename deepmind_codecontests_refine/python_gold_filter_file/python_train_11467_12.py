# coding=utf-8


def coffee_problem():
    coffee_num_list = []
    cup_num, page_num = input().split(' ')
    coffee_num_per_cup = input().split(' ')
    cup_num = eval(cup_num)
    page_num = eval(page_num)
    for cup_idx in range(cup_num):
        coffee_num_list.append(eval(coffee_num_per_cup[cup_idx]))
    coffee_num_list.sort(reverse=True)
    if sum(coffee_num_list) < page_num:
        print(-1)
        return
    for i in range(1, cup_num + 1):
        done_page_num = 0
        for j in range(cup_num):
            done_page_num += max(coffee_num_list[j] - j // i, 0)
            if done_page_num >= page_num:
                print(i)
                return


if __name__ == '__main__':
    coffee_problem()
