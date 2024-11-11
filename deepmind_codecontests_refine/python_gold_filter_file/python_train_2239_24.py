house_to_shop1_dist, house_to_shop2_dist, shop1_to_shop2_dist = map(int, input().split())

# Outline the unique costs
cost1 = house_to_shop1_dist + shop1_to_shop2_dist + house_to_shop2_dist
cost2 = 2 * (house_to_shop1_dist + house_to_shop2_dist)
cost3 = 2 * (house_to_shop1_dist + shop1_to_shop2_dist)
cost4 = 2 * (house_to_shop2_dist + shop1_to_shop2_dist)

print(min(cost1, cost2, cost3, cost4))
